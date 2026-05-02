// Function : FUN_400f69d4
// Address  : 0x400f69d4
// Size     : 85 bytes


undefined4 FUN_400f69d4(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 < 3) {
    iVar2 = param_1 * 0x10 + 0x3ffbdc7c;
    (*(code *)&SUB_40092a98)(iVar2,0xffffffff);
    FUN_400fe05c(param_1 * 0x10 + 0x3ffbdc78,param_2);
    (*(code *)&SUB_40092bec)(iVar2);
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"th","_select",uVar1,"th","tr_mask",0x13c);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

