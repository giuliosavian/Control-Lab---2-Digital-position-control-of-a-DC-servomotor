  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
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
    ;% Auto data (REALTIME_PART1_discretefeedforward_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% REALTIME_PART1_discretefeedforward_P.ctrl
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% REALTIME_PART1_discretefeedforward_P.sens
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% REALTIME_PART1_discretefeedforward_P.BEMF_comp
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART1_discretefeedforward_P.Beq_hat
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART1_discretefeedforward_P.K_w
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PART1_discretefeedforward_P.deg2rad
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% REALTIME_PART1_discretefeedforward_P.degs2rpm
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% REALTIME_PART1_discretefeedforward_P.friction_comp
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% REALTIME_PART1_discretefeedforward_P.inertia_comp
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
	  ;% REALTIME_PART1_discretefeedforward_P.rad2deg
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 7;
	
	  ;% REALTIME_PART1_discretefeedforward_P.rpm2rads
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 8;
	
	  ;% REALTIME_PART1_discretefeedforward_P.tau_hat
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 9;
	
	  ;% REALTIME_PART1_discretefeedforward_P.AnalogOutput_FinalValue
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 10;
	
	  ;% REALTIME_PART1_discretefeedforward_P.AnalogOutput_InitialValue
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 11;
	
	  ;% REALTIME_PART1_discretefeedforward_P.EncoderInput_InputFilter
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 12;
	
	  ;% REALTIME_PART1_discretefeedforward_P.EncoderInput_MaxMissedTicks
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 13;
	
	  ;% REALTIME_PART1_discretefeedforward_P.AnalogOutput_MaxMissedTicks
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 14;
	
	  ;% REALTIME_PART1_discretefeedforward_P.RepeatingSequenceStair_OutValues
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 15;
	
	  ;% REALTIME_PART1_discretefeedforward_P.EncoderInput_YieldWhenWaiting
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 21;
	
	  ;% REALTIME_PART1_discretefeedforward_P.AnalogOutput_YieldWhenWaiting
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% REALTIME_PART1_discretefeedforward_P.EncoderInput_Channels
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART1_discretefeedforward_P.AnalogOutput_Channels
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART1_discretefeedforward_P.AnalogOutput_RangeMode
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PART1_discretefeedforward_P.AnalogOutput_VoltRange
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% REALTIME_PART1_discretefeedforward_P.LimitedCounter_uplimit
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% REALTIME_PART1_discretefeedforward_P.Integrator_IC
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART1_discretefeedforward_P.Integrator1_IC
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART1_discretefeedforward_P.DiscreteTransferFcn_NumCoef
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PART1_discretefeedforward_P.DiscreteTransferFcn_DenCoef
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 4;
	
	  ;% REALTIME_PART1_discretefeedforward_P.DiscreteTransferFcn_InitialStates
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 6;
	
	  ;% REALTIME_PART1_discretefeedforward_P.Delay_InitialCondition
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 7;
	
	  ;% REALTIME_PART1_discretefeedforward_P.DiscreteTimeIntegrator_gainval
	  section.data(7).logicalSrcIdx = 31;
	  section.data(7).dtTransOffset = 8;
	
	  ;% REALTIME_PART1_discretefeedforward_P.DiscreteTimeIntegrator_IC
	  section.data(8).logicalSrcIdx = 32;
	  section.data(8).dtTransOffset = 9;
	
	  ;% REALTIME_PART1_discretefeedforward_P.Saturation_UpperSat
	  section.data(9).logicalSrcIdx = 33;
	  section.data(9).dtTransOffset = 10;
	
	  ;% REALTIME_PART1_discretefeedforward_P.Saturation_LowerSat
	  section.data(10).logicalSrcIdx = 34;
	  section.data(10).dtTransOffset = 11;
	
	  ;% REALTIME_PART1_discretefeedforward_P.SpeedFilter_A
	  section.data(11).logicalSrcIdx = 35;
	  section.data(11).dtTransOffset = 12;
	
	  ;% REALTIME_PART1_discretefeedforward_P.SpeedFilter_C
	  section.data(12).logicalSrcIdx = 36;
	  section.data(12).dtTransOffset = 14;
	
	  ;% REALTIME_PART1_discretefeedforward_P.AccelerationFilter_A
	  section.data(13).logicalSrcIdx = 37;
	  section.data(13).dtTransOffset = 16;
	
	  ;% REALTIME_PART1_discretefeedforward_P.AccelerationFilter_C
	  section.data(14).logicalSrcIdx = 38;
	  section.data(14).dtTransOffset = 18;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% REALTIME_PART1_discretefeedforward_P.Constant_Value
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART1_discretefeedforward_P.Output_InitialCondition
	  section.data(2).logicalSrcIdx = 40;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART1_discretefeedforward_P.ManualSwitch_CurrentSetting
	  section.data(3).logicalSrcIdx = 41;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PART1_discretefeedforward_P.FixPtConstant_Value
	  section.data(4).logicalSrcIdx = 42;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
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
    nTotSects     = 2;
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
    ;% Auto data (REALTIME_PART1_discretefeedforward_B)
    ;%
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% REALTIME_PART1_discretefeedforward_B.Output
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART1_discretefeedforward_B.ZeroOrderHold
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART1_discretefeedforward_B.Integrator
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PART1_discretefeedforward_B.ZeroOrderHold1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% REALTIME_PART1_discretefeedforward_B.derivativegain1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% REALTIME_PART1_discretefeedforward_B.ZeroOrderHold2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% REALTIME_PART1_discretefeedforward_B.pulse2deg
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% REALTIME_PART1_discretefeedforward_B.Sum1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% REALTIME_PART1_discretefeedforward_B.DiscreteTimeIntegrator
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 8;
	
	  ;% REALTIME_PART1_discretefeedforward_B.ManualSwitch
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 9;
	
	  ;% REALTIME_PART1_discretefeedforward_B.Saturation
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 10;
	
	  ;% REALTIME_PART1_discretefeedforward_B.ZeroOrderHold1_o
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 11;
	
	  ;% REALTIME_PART1_discretefeedforward_B.wlrpm
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 12;
	
	  ;% REALTIME_PART1_discretefeedforward_B.ZeroOrderHold1_n
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 13;
	
	  ;% REALTIME_PART1_discretefeedforward_B.accrpms
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 14;
	
	  ;% REALTIME_PART1_discretefeedforward_B.ZeroOrderHold_m
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 15;
	
	  ;% REALTIME_PART1_discretefeedforward_B.derivativegain_p
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 16;
	
	  ;% REALTIME_PART1_discretefeedforward_B.K_w
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% REALTIME_PART1_discretefeedforward_B.FixPtSwitch
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    nTotSects     = 3;
    sectIdxOffset = 2;
    
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
    ;% Auto data (REALTIME_PART1_discretefeedforward_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% REALTIME_PART1_discretefeedforward_DW.DiscreteTransferFcn_states
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART1_discretefeedforward_DW.Delay_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART1_discretefeedforward_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PART1_discretefeedforward_DW.DiscreteTransferFcn_tmp
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% REALTIME_PART1_discretefeedforward_DW.EncoderInput_PWORK
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PART1_discretefeedforward_DW.AnalogOutput_PWORK
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PART1_discretefeedforward_DW.Scope3_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PART1_discretefeedforward_DW.Scope_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% REALTIME_PART1_discretefeedforward_DW.Output_DSTATE
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
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


  targMap.checksum0 = 3587552589;
  targMap.checksum1 = 2952948338;
  targMap.checksum2 = 481500872;
  targMap.checksum3 = 3756009429;

