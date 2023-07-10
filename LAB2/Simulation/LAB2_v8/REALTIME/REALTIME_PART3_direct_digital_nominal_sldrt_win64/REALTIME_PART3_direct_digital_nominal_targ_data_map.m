  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
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
    ;% Auto data (REALTIME_PART3_direct_digital_nominal_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% REALTIME_PART3_direct_digital_nominal_P.sens
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% REALTIME_PART3_direct_digital_nominal_P.GAMMA0
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.H0
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 2;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.N_u
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 4;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.N_x
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 5;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.PHI0
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 7;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.deg2rad
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 8;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.degs2rpm
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 9;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.step_size
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 10;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.AnalogOutput_FinalValue
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 11;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.AnalogOutput_InitialValue
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 12;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.EncoderInput_InputFilter
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 13;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.AnalogOutput_MaxMissedTicks
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 14;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.EncoderInput_MaxMissedTicks
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 15;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.AnalogOutput_YieldWhenWaiting
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 16;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.EncoderInput_YieldWhenWaiting
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% REALTIME_PART3_direct_digital_nominal_P.AnalogOutput_Channels
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.EncoderInput_Channels
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.AnalogOutput_RangeMode
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.AnalogOutput_VoltRange
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% REALTIME_PART3_direct_digital_nominal_P.Step_Time
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.Step_Y0
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.RateTransition_InitialCondition
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.Statefeedback_Gain
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 3;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.Saturation_UpperSat
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 5;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.Saturation_LowerSat
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 6;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.SpeedFilter_A
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 7;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.SpeedFilter_C
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 9;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.DiscreteStateSpace_D
	  section.data(9).logicalSrcIdx = 28;
	  section.data(9).dtTransOffset = 11;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.DiscreteStateSpace_InitialCondition
	  section.data(10).logicalSrcIdx = 29;
	  section.data(10).dtTransOffset = 15;
	
	  ;% REALTIME_PART3_direct_digital_nominal_P.Gain_Gain
	  section.data(11).logicalSrcIdx = 30;
	  section.data(11).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
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
    ;% Auto data (REALTIME_PART3_direct_digital_nominal_B)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% REALTIME_PART3_direct_digital_nominal_B.thl_ref
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART3_direct_digital_nominal_B.RateTransition
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART3_direct_digital_nominal_B.Saturation
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% REALTIME_PART3_direct_digital_nominal_B.pulse2deg
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% REALTIME_PART3_direct_digital_nominal_B.wlrpm
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% REALTIME_PART3_direct_digital_nominal_B.Sum
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% REALTIME_PART3_direct_digital_nominal_B.TmpSignalConversionAtDiscreteStateSpaceInport1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
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
    ;% Auto data (REALTIME_PART3_direct_digital_nominal_DW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% REALTIME_PART3_direct_digital_nominal_DW.DiscreteStateSpace_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART3_direct_digital_nominal_DW.RateTransition_Buffer0
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% REALTIME_PART3_direct_digital_nominal_DW.AnalogOutput_PWORK
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART3_direct_digital_nominal_DW.EncoderInput_PWORK
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART3_direct_digital_nominal_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
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


  targMap.checksum0 = 2802865753;
  targMap.checksum1 = 464522275;
  targMap.checksum2 = 3890288593;
  targMap.checksum3 = 1179607056;

