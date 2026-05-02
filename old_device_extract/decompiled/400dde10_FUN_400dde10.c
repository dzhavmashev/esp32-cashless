// Function : FUN_400dde10
// Address  : 0x400dde10
// Size     : 406 bytes


undefined4 FUN_400dde10(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  if (((((byte)param_1[2] < 0x28) && (0.0 < *(float *)(param_1 + 8))) &&
      ((ushort)(*(short *)(param_1 + 0xe) - 1U) < 5000)) &&
     (((ushort)(*(short *)(param_1 + 0x10) - 1U) < 5000 &&
      ((ushort)(*(short *)(param_1 + 0x66) - 1U) < 5000)))) {
    cVar1 = *param_1;
    if (cVar1 == '\x01') {
      if ((byte)(param_1[100] - 1U) < 10) {
LAB_400ddf6d:
        FUN_400f0780(0x3ffc5490,"troller");
        uVar2 = (*(code *)&LAB_40170217_1)(0xa0);
        FUN_400dfd98();
        return uVar2;
      }
    }
    else if (cVar1 == '\x02') {
      if ((0.0 < *(float *)(param_1 + 0x68)) && (*(float *)(param_1 + 0x68) <= 60.0)) {
LAB_400ddea0:
        FUN_400f0780(0x3ffc5490,"troller");
        uVar2 = (*(code *)&LAB_40170217_1)(0x7c);
        FUN_400dc02c();
        return uVar2;
      }
    }
    else if (cVar1 == '\x04') {
      if (((((byte)param_1[0x7b] < 0x28) && ((byte)param_1[0x7c] < 0x28)) &&
          ((byte)param_1[0x7d] < 0x28)) &&
         (((param_1[0x7e] & 0xdfU) == 0x40 || (param_1[0x7e] == 0x10)))) {
        FUN_400f0780(0x3ffc5490,"troller");
        uVar2 = (*(code *)&LAB_40170217_1)(0xf8);
        FUN_400df0fc();
        return uVar2;
      }
    }
    else {
      if (cVar1 != '\x05') {
        if (cVar1 == '\x01') goto LAB_400ddf6d;
        if (cVar1 == '\0') {
          FUN_400f0780(0x3ffc5490,"uration");
          uVar2 = (*(code *)&LAB_40170217_1)(0xa8);
          FUN_400dd37c();
          return uVar2;
        }
        if (cVar1 != '\x02') {
          if (cVar1 != '\x03') {
            FUN_400f06a4(0x3ffc5490,"troller");
            return 0;
          }
          FUN_400f0780(0x3ffc5490,"troller");
          uVar2 = (*(code *)&LAB_40170217_1)(0xa8);
          FUN_400dd918();
          return uVar2;
        }
        goto LAB_400ddea0;
      }
      if (((byte)param_1[0x7b] < 0x28) && ((byte)param_1[0x7c] < 0x28)) {
        FUN_400f0780(0x3ffc5490,"troller");
        uVar2 = (*(code *)&LAB_40170217_1)(0x120);
        FUN_400de254();
        return uVar2;
      }
    }
  }
  FUN_400f0780(0x3ffc5490,&PTR_FUN_3f405f8c);
  return 0;
}

