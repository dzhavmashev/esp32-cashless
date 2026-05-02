// Function : FUN_400f6aa8
// Address  : 0x400f6aa8
// Size     : 174 bytes


undefined4 FUN_400f6aa8(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (param_1 < 3) {
    piVar4 = (int *)(param_1 * 4 + 0x3ffc5588);
    if (*piVar4 == 0) {
      uVar1 = (*(code *)&SUB_40094b80)();
      memw();
      FUN_4012113c(1,"th"," error\n",uVar1,"th","tx_intr",0x206);
      uVar1 = 0x103;
    }
    else {
      iVar2 = (*(code *)&SUB_40094d60)(param_2 << 2);
      uVar1 = 0x101;
      if (iVar2 != 0) {
        iVar3 = param_1 * 0x10 + 0x3ffbdc7c;
        (*(code *)&SUB_40092a98)(iVar3,0xffffffff);
        iVar6 = *piVar4;
        uVar5 = *(undefined4 *)(iVar6 + 0xb0);
        *(int *)(iVar6 + 0xac) = param_2;
        *(int *)(iVar6 + 0xb0) = iVar2;
        *(undefined4 *)(iVar6 + 0xa8) = 0;
        *(undefined4 *)(iVar6 + 0xa4) = 0;
        memw();
        (*(code *)&SUB_40092bec)(iVar3);
        uVar1 = 0;
        (*(code *)&SUB_40094d80)(uVar5);
      }
    }
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"th","_select",uVar1,"th","tx_intr",0x205);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

