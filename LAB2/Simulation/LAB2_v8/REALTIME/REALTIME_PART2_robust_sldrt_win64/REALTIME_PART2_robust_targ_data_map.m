  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (REALTIME_PART2_robust_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% REALTIME_PART2_robust_P.ctrl
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% REALTIME_PART2_robust_P.sens
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% REALTIME_PART2_robust_P.GAMMA
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART2_robust_P.H0
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 2;
	
	  ;% REALTIME_PART2_robust_P.Ki
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 4;
	
	  ;% REALTIME_PART2_robust_P.N_u
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 5;
	
	  ;% REALTIME_PART2_robust_P.N_x
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 6;
	
	  ;% REALTIME_PART2_robust_P.PHI
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 8;
	
	  ;% REALTIME_PART2_robust_P.deg2rad
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 9;
	
	  ;% REALTIME_PART2_robust_P.degs2rpm
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 10;
	
	  ;% REALTIME_PART2_robust_P.step_size
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 11;
	
	  ;% REALTIME_PART2_robust_P.AnalogOutput_FinalValue
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 12;
	
	  ;% REALTIME_PART2_robust_P.AnalogOutput_InitialValue
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 13;
	
	  ;% REALTIME_PART2_robust_P.EncoderInput_InputFilter
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 14;
	
	  ;% REALTIME_PART2_robust_P.AnalogOutput_MaxMissedTicks
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 15;
	
	  ;% REALTIME_PART2_robust_P.EncoderInput_MaxMissedTicks
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 16;
	
	  ;% REALTIME_PART2_robust_P.AnalogOutput_YieldWhenWaiting
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 17;
	
	  ;% REALTIME_PART2_robust_P.EncoderInput_YieldWhenWaiting
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 18;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% REALTIME_PART2_robust_P.AnalogOutput_Channels
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART2_robust_P.EncoderInput_Channels
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART2_robust_P.AnalogOutput_RangeMode
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PART2_robust_P.AnalogOutput_VoltRange
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% REALTIME_PART2_robust_P.Step_Time
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART2_robust_P.Step_Y0
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART2_robust_P.Delay1_InitialCondition
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PART2_robust_P.Statefeedback_Gain
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 3;
	
	  ;% REALTIME_PART2_robust_P.Highpassfilter1_Denominator
	  section.data(5).logicalSrcIdx = 26;
	  section.data(5).dtTransOffset = 5;
	
	  ;% REALTIME_PART2_robust_P.Saturation_UpperSat
	  section.data(6).logicalSrcIdx = 27;
	  section.data(6).dtTransOffset = 7;
	
	  ;% REALTIME_PART2_robust_P.Saturation_LowerSat
	  section.data(7).logicalSrcIdx = 28;
	  section.data(7).dtTransOffset = 8;
	
	  ;% REALTIME_PART2_robust_P.Delay3_InitialCondition
	  section.data(8).logicalSrcIdx = 29;
	  section.data(8).dtTransOffset = 9;
	
	  ;% REALTIME_PART2_robust_P.Statefeedback1_Gain
	  section.data(9).logicalSrcIdx = 30;
	  section.data(9).dtTransOffset = 10;
	
	  ;% REALTIME_PART2_robust_P.DiscreteTimeIntegrator1_gainval
	  section.data(10).logicalSrcIdx = 31;
	  section.data(10).dtTransOffset = 12;
	
	  ;% REALTIME_PART2_robust_P.DiscreteTimeIntegrator1_IC
	  section.data(11).logicalSrcIdx = 32;
	  section.data(11).dtTransOffset = 13;
	
	  ;% REALTIME_PART2_robust_P.Saturation1_UpperSat
	  section.data(12).logicalSrcIdx = 33;
	  section.data(12).dtTransOffset = 14;
	
	  ;% REALTIME_PART2_robust_P.Saturation1_LowerSat
	  section.data(13).logicalSrcIdx = 34;
	  section.data(13).dtTransOffset = 15;
	
	  ;% REALTIME_PART2_robust_P.SpeedFilter1_A
	  section.data(14).logicalSrcIdx = 35;
	  section.data(14).dtTransOffset = 16;
	
	  ;% REALTIME_PART2_robust_P.SpeedFilter1_C
	  section.data(15).logicalSrcIdx = 36;
	  section.data(15).dtTransOffset = 18;
	
	  ;% REALTIME_PART2_robust_P.DiscreteStateSpace1_D
	  section.data(16).logicalSrcIdx = 37;
	  section.data(16).dtTransOffset = 20;
	
	  ;% REALTIME_PART2_robust_P.DiscreteStateSpace1_InitialCondition
	  section.data(17).logicalSrcIdx = 38;
	  section.data(17).dtTransOffset = 24;
	
	  ;% REALTIME_PART2_robust_P.Gain_Gain
	  section.data(18).logicalSrcIdx = 39;
	  section.data(18).dtTransOffset = 25;
	
	  ;% REALTIME_PART2_robust_P.Delay_InitialCondition
	  section.data(19).logicalSrcIdx = 40;
	  section.data(19).dtTransOffset = 27;
	
	  ;% REALTIME_PART2_robust_P.Delay2_InitialCondition
	  section.data(20).logicalSrcIdx = 41;
	  section.data(20).dtTransOffset = 28;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% REALTIME_PART2_robust_P.ManualSwitch2_CurrentSetting
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (REALTIME_PART2_robust_B)
    ;%
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% REALTIME_PART2_robust_B.Inputfeedforward
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART2_robust_B.Statefeedback
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART2_robust_B.Sum
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PART2_robust_B.Saturation
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% REALTIME_PART2_robust_B.Sum5
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% REALTIME_PART2_robust_B.Saturation1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% REALTIME_PART2_robust_B.ManualSwitch2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% REALTIME_PART2_robust_B.thl_meas
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% REALTIME_PART2_robust_B.wlrpm
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% REALTIME_PART2_robust_B.Sum_b
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% REALTIME_PART2_robust_B.K_w
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 11;
	
	  ;% REALTIME_PART2_robust_B.K_w1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 12;
	
	  ;% REALTIME_PART2_robust_B.Sum1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 13;
	
	  ;% REALTIME_PART2_robust_B.Sum4
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 14;
	
	  ;% REALTIME_PART2_robust_B.Sum9
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 15;
	
	  ;% REALTIME_PART2_robust_B.TmpSignalConversionAtDiscreteStateSpace1Inport1
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (REALTIME_PART2_robust_DW)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% REALTIME_PART2_robust_DW.Delay1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART2_robust_DW.Delay3_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% REALTIME_PART2_robust_DW.DiscreteTimeIntegrator1_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% REALTIME_PART2_robust_DW.DiscreteStateSpace1_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% REALTIME_PART2_robust_DW.Delay_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% REALTIME_PART2_robust_DW.Delay2_DSTATE
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% REALTIME_PART2_robust_DW.AnalogOutput_PWORK
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART2_robust_DW.EncoderInput_PWORK
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART2_robust_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PART2_robust_DW.Scope_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 6;
	
	  ;% REALTIME_PART2_robust_DW.Scope1_PWORK_g.LoggedData
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3354986832;
  targMap.checksum1 = 131843889;
  targMap.checksum2 = 2500180393;
  targMap.checksum3 = 4262535532;

