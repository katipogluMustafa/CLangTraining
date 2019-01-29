/* Drone Yönetimi için bi çeşit projenin Iphone uygulamasında kullanılan kod.*/
/* Link: https://github.com/evenator/senior-project/blob/8c919e88ed8ca36e02ea1c51c1b95d0592f43dc9/ARDrone_sdk/ControlEngine/iPhone/Classes/ControlData.c */

void checkErrors(void){

	input_state_t* input_state = ardrone_tool_get_input_state();
	
	strcpy(ctrldata.error_msg, "");
	
	if(!ctrldata.wifiReachabled)
	{
		strcpy(ctrldata.error_msg, "WIFI NOT REACHABLE");
		resetControlData();
	}
	else
	{
		if(ctrldata.needAnimation >= 0)
		{
			ardrone_at_set_anim(ctrldata.needAnimation, MAYDAY_TIMEOUT[ctrldata.needAnimation]);
			ctrldata.needAnimation = -1;
		}
		
		if(ctrldata.needVideoSwitch >= 0)
		{
			ardrone_at_zap(ctrldata.needVideoSwitch);
			ctrldata.needVideoSwitch = -1;
		}
		
		if(ctrldata.needChangeEnemyColor >= 0)
		{
			ARDRONE_CONFIGURATION_SET(enemy_colors, ctrldata.needChangeEnemyColor);
			ctrldata.needChangeEnemyColor = -1;
		}	
		
		if(ctrldata.needChangeEnemyOutdoorShell >= 0)
		{
			ARDRONE_CONFIGURATION_SET(enemy_without_shell, ctrldata.needChangeEnemyOutdoorShell);
			ctrldata.needChangeEnemyOutdoorShell = -1;
		}
		
		if(ctrldata.needLedAnimation >= 0)
		{
			ardrone_at_set_led_animation(ctrldata.needLedAnimation, ctrldata.ledAnimFreq, ctrldata.ledAnimDuration);
			ctrldata.needLedAnimation = -1;
		}	
		
		if(ctrldata.needSetTakeOff)
		{
			if(ctrlnavdata.emergencyLanding)
			{
				ctrldata.needSetEmergency = TRUE;
			}
			else
			{
				printf("Take off ...\n");
				if(!ctrlnavdata.startPressed)
					ardrone_tool_set_ui_pad_start(1);
				else
					ardrone_tool_set_ui_pad_start(0);
				ctrldata.needSetTakeOff = FALSE;
			}
		}
		
		if(ctrldata.needSetEmergency)
		{
			ctrldata.isInEmergency = ctrlnavdata.emergencyLanding;
			ardrone_tool_set_ui_pad_select(1);
			ctrldata.needSetEmergency = FALSE;
		}
		
		if( ctrldata.needSetNavdataDemo)
		{
			if( control_ack_configure_navdata_demo(ctrldata.navdata_demo))
				ctrldata.needSetNavdataDemo = FALSE;
		}
		else if( ctrldata.needSetPairing )
		{
			if(control_ack_configure_mac_address(ctrldata.pairing_mac_address))
				ctrldata.needSetPairing = FALSE;
		}
		else if(ctrldata.needSetFrequency)
		{
			if(control_ack_configure_ultrasound_frequency(!ctrldata.is_client))
				ctrldata.needSetFrequency = FALSE;
		}
		else if(ctrldata.needChangeCameraDetection >= 0)
		{
			if(control_ack_configure_detect_type((CAD_TYPE)ctrldata.needChangeCameraDetection))
				ctrldata.needChangeCameraDetection = -1;
		}	
		else if(ctrldata.needGetConfiguration)
		{
			//PRINT("Request configuration file\n");
			if(control_get_configuration())
				ctrldata.needGetConfiguration = FALSE;
		}
		
		if((ctrldata.framecounter % (kFPS / 2)) == 0)
		{
			if(ctrlnavdata.bootstrap)
			{
				setNavdataDemo(TRUE);
				ctrldata.needSetFrequency = TRUE;
				ctrldata.needGetConfiguration = TRUE;
			}
		}
		
		if(ardrone_navdata_client_get_num_retries() >= NAVDATA_MAX_RETRIES)
		{
			strcpy(ctrldata.error_msg, "CONTROL LINK NOT AVAILABLE");
			resetControlData();
		}
		else if(ctrlnavdata.emergencyLanding)
		{
			if(!ctrldata.isInEmergency && input_state->select)
				ardrone_tool_set_ui_pad_select(0);
			
			if(ctrlnavdata.cutoutProblem)
			{
				strcpy(ctrldata.error_msg, "CUT OUT EMERGENCY");
			}
			else if(ctrlnavdata.motorsProblem)
			{
				strcpy(ctrldata.error_msg, "MOTORS EMERGENCY");
			}
			else if(ctrlnavdata.cameraProblem)
			{
				strcpy(ctrldata.error_msg, "CAMERA EMERGENCY");
			}
			else if(ctrlnavdata.adcProblem)
			{
				strcpy(ctrldata.error_msg, "PIC WATCHDOG EMERGENCY");
			}
			else if(ctrlnavdata.adcVersionProblem)
			{
				strcpy(ctrldata.error_msg, "PIC VERSION EMERGENCY");
			}
			else if(ctrlnavdata.anglesProblem)
			{
				strcpy(ctrldata.error_msg, "TOO MUCH ANGLE EMERGENCY");
			}
			else if(ctrlnavdata.vbatLowProblem)
			{
				strcpy(ctrldata.error_msg, "BATTERY LOW EMERGENCY");
			}
			else if(ctrlnavdata.userEmergency)
			{
				strcpy(ctrldata.error_msg, "USER EMERGENCY");
			}
			else if(ctrlnavdata.ultrasoundProblem)
			{
				strcpy(ctrldata.error_msg, "ULTRASOUND EMERGENCY");
			}
			else
			{
				strcpy(ctrldata.error_msg, "UNKNOWN EMERGENCY");
			}
						
			strcpy(ctrldata.emergency_msg, "");
			strcpy(ctrldata.takeoff_msg, "take_off");
			
			resetControlData();
			ardrone_tool_start_reset();
		}
		else if(!ctrlnavdata.emergencyLanding)
		{	
			if(ctrldata.isInEmergency && input_state->select)
			{
				ardrone_tool_set_ui_pad_select(0);
			}
			
			if(video_stage_get_num_retries() > VIDEO_MAX_RETRIES)
			{
				strcpy(ctrldata.error_msg, "VIDEO CONNECTION ALERT");
			}
			else if(ctrlnavdata.vbatLowProblem)
			{
				strcpy(ctrldata.error_msg, "BATTERY LOW ALERT");
			}
			else if(ctrlnavdata.ultrasoundProblem)
			{
				strcpy(ctrldata.error_msg, "ULTRASOUND ALERT");
			}
			else if(ctrlnavdata.visionProblem && ctrlnavdata.flyingState)
			{
				strcpy(ctrldata.error_msg, "VISION ALERT");
			}

			if(!ctrlnavdata.timerElapsed)
				strcpy(ctrldata.emergency_msg, "emergency");
			
			if(input_state->start)
			{
				if(ctrlnavdata.startPressed)
				{
					strcpy(ctrldata.takeoff_msg, "take_land");
				}
				else
				{	
					strcpy(ctrldata.takeoff_msg, "take_off");
					strcpy(ctrldata.error_msg, "START NOT RECEIVED");
					
				}
			}
			else
			{
				strcpy(ctrldata.takeoff_msg, "take_off");
			}			
		}
	}
}
