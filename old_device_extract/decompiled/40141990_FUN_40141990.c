// Function : FUN_40141990
// Address  : 0x40141990
// Size     : 56 bytes


undefined4 FUN_40141990(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  uint uStack_28;
  undefined4 uStack_24;
  
  memw();
  uStack_28 = param_4;
  uStack_24 = param_3;
  (*(code *)&SUB_4008b530)(param_3,0,0x10);
  memw();
  uVar1 = FUN_401418a4(param_1,param_2,0xff,param_4 & 0xff,0,0,0x40141704,&uStack_28);
  return uVar1;
}

