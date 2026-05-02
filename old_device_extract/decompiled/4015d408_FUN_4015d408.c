// Function : FUN_4015d408
// Address  : 0x4015d408
// Size     : 107 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015d408(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  memw();
  FUN_40147fe4(1,4,4,0x3f4344f6,*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5),
               *(undefined1 *)(param_1 + 6),*(undefined1 *)(param_1 + 7),
               *(undefined1 *)(param_1 + 8),*(undefined1 *)(param_1 + 9));
  for (uVar2 = 0; uVar2 < DAT_3ffca0b6; uVar2 = uVar2 + 1 & 0xff) {
    iVar1 = (uVar2 + 0x3a8) * 4;
    iVar3 = *(int *)(iVar1 + 0x3ffc9200);
    if (param_1 != iVar3) {
      (*(code *)&SUB_4008b530)(iVar3,0);
      *(undefined4 *)(iVar1 + 0x3ffc9200) = 0;
    }
  }
  DAT_3ffca0b6 = 1;
  memw();
  _DAT_3ffca0a0 = param_1;
  memw();
  return;
}

