// Function : FUN_40155364
// Address  : 0x40155364
// Size     : 155 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40155364(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = _DAT_3ffbfd50;
  *(int *)(param_1 + 4) = _DAT_3ffbfd50;
  *(undefined1 *)(iVar1 + 0x9b) = 0xff;
  *(undefined4 *)(iVar1 + 0x30) = 0x78;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined4 *)(iVar1 + 0x38) = 0x168;
  *(undefined1 *)(iVar1 + 0x118) = 0x1e;
  memw();
  *(undefined4 *)(iVar1 + 0x4c) = 0x3ffbfd40;
  *(undefined1 *)(iVar1 + 0x48) = 0xe;
  *(undefined1 *)(iVar1 + 0x110) = 0;
  memw();
  pcVar2 = *(code **)(_DAT_3ffc1a34 + 0xf4);
  *(undefined4 *)(iVar1 + 0x114) = 0;
  memw();
  (*pcVar2)(iVar1 + 4,0x401550f8,0);
  (**(code **)(_DAT_3ffc1a34 + 0xf4))(_DAT_3ffbfd50 + 0x18,0x401550e8,0);
  iVar1 = _DAT_3ffbfd50;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  *(int *)(param_1 + 0x1a8) = param_1 + 0x1a4;
  memw();
  FUN_40147fe4(1,9,5,0x3f436103,*(undefined1 *)(iVar1 + 0x9b),*(undefined4 *)(iVar1 + 0x34),
               *(undefined4 *)(iVar1 + 0x30),*(undefined4 *)(iVar1 + 0x38),
               *(undefined1 *)(iVar1 + 0x48),*(undefined1 *)(iVar1 + 0x110));
  return;
}

