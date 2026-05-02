// Function : FUN_401552e8
// Address  : 0x401552e8
// Size     : 105 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401552e8(int param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  code *pcVar7;
  undefined8 uVar8;
  
  uVar5 = 0x80;
  if (param_2 != 0) {
    uVar5 = 0x50;
  }
  if (((1 << 0x20 - (0x20 - (uVar5 >> 4)) & _DAT_3ffc8a58) != 0) ||
     (uVar4 = 0, (*(byte *)(_DAT_3ffbfd50 + 0x46) & 1) != 0)) {
    iVar6 = *(int *)(*(int *)(param_1 + 4) + 4);
    pcVar7 = *(code **)(_DAT_3ffc89a4 + 0x50);
    uVar3 = *(undefined2 *)(param_1 + 0x16);
    cVar1 = **(char **)(param_1 + 0x10);
    uVar2 = *(undefined1 *)(*(int *)(param_1 + 0x2c) + 8);
    uVar8 = FUN_40167020(0);
    memw();
    uVar4 = (*pcVar7)(uVar5 >> 4,iVar6 + 0x18,uVar3,iVar6 + 10,(int)cVar1,uVar2,uVar8);
  }
  return uVar4;
}

