// Function : FUN_400f6a2c
// Address  : 0x400f6a2c
// Size     : 122 bytes


undefined4 FUN_400f6a2c(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 < 3) {
    iVar2 = param_1 * 0x10 + 0x3ffbdc7c;
    (*(code *)&SUB_40092a98)(iVar2,0xffffffff);
    iVar3 = *(int *)(param_1 * 4 + 0x3ffc5588);
    *(uint *)(iVar3 + 0xa0) = *(uint *)(iVar3 + 0xa0) & (param_2 ^ 0xffffffff);
    iVar3 = *(int *)(param_1 * 0x10 + 0x3ffbdc78);
    memw();
    memw();
    *(uint *)(iVar3 + 0xc) = (param_2 ^ 0xffffffff) & *(uint *)(iVar3 + 0xc);
    memw();
    (*(code *)&SUB_40092bec)(iVar2);
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"th","_select",uVar1,"th","e_reset",0x197);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

