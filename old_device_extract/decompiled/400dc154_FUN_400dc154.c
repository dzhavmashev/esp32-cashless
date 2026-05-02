// Function : FUN_400dc154
// Address  : 0x400dc154
// Size     : 121 bytes


undefined4 FUN_400dc154(undefined4 param_1,char *param_2)

{
  char *pcVar1;
  float fVar2;
  undefined8 uVar3;
  
  if (*param_2 == '\x02') {
    pcVar1 = "d: %d)\n";
    if ((byte)param_2[2] < 0x28) {
      if ((ushort)(*(short *)(param_2 + 0x66) - 1U) < 5000) {
        fVar2 = *(float *)(param_2 + 0x68);
        if ((0.0 < fVar2) && (fVar2 <= 60.0)) {
          return 1;
        }
        uVar3 = (*(code *)&SUB_40002c34)(fVar2,"d: %d)\n");
        FUN_400f06a4(0x3ffc5490,"000ms)\n",(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
        return 0;
      }
      pcVar1 = "in: %d\n";
    }
    FUN_400f06a4(0x3ffc5490,pcVar1);
  }
  else {
    FUN_400f06a4(0x3ffc5490,"to loop",*param_2,2);
  }
  return 0;
}

