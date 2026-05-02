// Function : FUN_40123904
// Address  : 0x40123904
// Size     : 76 bytes


void FUN_40123904(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_24;
  
  FUN_401049d0(param_1,param_2,&uStack_44);
  *param_3 = uStack_44;
  memw();
  uVar1 = FUN_40103150(uStack_40);
  param_3[1] = uVar1;
  memw();
  uVar1 = FUN_40103150(uStack_3c);
  param_3[3] = uStack_38;
  param_3[4] = uStack_34;
  param_3[2] = uVar1;
  param_3[6] = uStack_2c;
  memw();
  uVar1 = FUN_40103150(uStack_28);
  param_3[7] = uVar1;
  *(undefined1 *)(param_3 + 8) = uStack_24;
  memw();
  memw();
  return;
}

