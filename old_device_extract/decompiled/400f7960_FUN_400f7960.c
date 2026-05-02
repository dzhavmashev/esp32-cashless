// Function : FUN_400f7960
// Address  : 0x400f7960
// Size     : 229 bytes


undefined4 FUN_400f7960(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  if (param_1 < 3) {
    piVar5 = (int *)(param_1 * 4 + 0x3ffc5588);
    uVar1 = 0;
    iVar2 = *piVar5;
    if (iVar2 != 0) {
      iVar4 = param_1 * 0x10;
      memw();
      FUN_4011eb64(*(undefined4 *)(iVar2 + 8));
      FUN_400f6b58(param_1);
      FUN_400f6b6c(param_1);
      iVar2 = iVar4 + 0x3ffbdc7c;
      (*(code *)&SUB_40092a98)(iVar2,0xffffffff);
      iVar6 = *piVar5;
      iVar7 = *(int *)(iVar6 + 0xb0);
      if (iVar7 != 0) {
        *(undefined4 *)(iVar6 + 0xb0) = 0;
        *(undefined4 *)(iVar6 + 0xa4) = 0;
        *(undefined4 *)(iVar6 + 0xa8) = 0;
      }
      memw();
      (*(code *)&SUB_40092bec)(iVar2);
      (*(code *)&SUB_40094d80)(iVar7);
      puVar3 = (undefined4 *)(param_1 * 4 + 0x3ffc5588);
      FUN_400f6584(*puVar3);
      *puVar3 = 0;
      memw();
      (*(code *)&SUB_40092a98)(iVar2,0xffffffff);
      if (*(char *)(iVar4 + 0x3ffbdc84) != '\0') {
        if (param_1 != 0) {
          FUN_400f55ec(*(undefined4 *)(&DAT_3f414520 + param_1 * 0x18));
        }
        *(undefined1 *)(iVar4 + 0x3ffbdc84) = 0;
        memw();
      }
      memw();
      (*(code *)&SUB_40092bec)(iVar2);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"th","_select",uVar1,"th","reshold",0x66c);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

