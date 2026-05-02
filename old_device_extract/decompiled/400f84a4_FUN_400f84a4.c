// Function : FUN_400f84a4
// Address  : 0x400f84a4
// Size     : 56 bytes


undefined4 FUN_400f84a4(int param_1)

{
  undefined4 uVar1;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uStack_22 = FUN_400f8368(param_1);
    memw();
    memw();
    uStack_21 = FUN_400f8368(param_1 + 0x20);
    memw();
    memw();
    uVar1 = FUN_4018487c(param_1,&uStack_22,1);
  }
  return uVar1;
}

