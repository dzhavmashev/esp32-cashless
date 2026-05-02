// Function : FUN_4015b458
// Address  : 0x4015b458
// Size     : 211 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015b458(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = _DAT_3ffbfdf0;
  iVar3 = _DAT_3ffbfdf0 + 4;
  pcVar2 = *(code **)(_DAT_3ffbfdf0 + 0x14);
  uVar4 = *(undefined4 *)(_DAT_3ffbfdf0 + 0x10);
  memw();
  FUN_40147fe4(1,8,5,0x3f43629a,*(undefined1 *)(_DAT_3ffbfdf0 + 4),
               *(undefined1 *)(_DAT_3ffbfdf0 + 5),*(undefined4 *)(_DAT_3ffbfdf0 + 8),
               *(undefined4 *)(_DAT_3ffbfdf0 + 0xc));
  if (*(char *)(iVar1 + 0x52) != *(char *)(iVar1 + 4)) {
    FUN_4015b284(iVar3);
  }
  if (pcVar2 != (code *)0x0) {
    FUN_40147fe4(1,8,5,0x3f436283,uVar4);
    (*pcVar2)(uVar4,0);
  }
  if (*(uint *)(iVar1 + 8) == 0) {
    if (*(uint *)(iVar1 + 0xc) == 0) {
      (*(code *)&SUB_4008b530)(iVar3,0,0x18);
      *(undefined1 *)(iVar1 + 4) = 0xff;
      memw();
      memw();
      return;
    }
  }
  else if (*(uint *)(iVar1 + 8) < *(uint *)(iVar1 + 0xc)) {
    FUN_40147fe4(1,8,5,0x3f436273);
    (**(code **)(_DAT_3ffc1a34 + 0xec))(_DAT_3ffbfdf0 + 0x24);
    (**(code **)(_DAT_3ffc1a34 + 0xe8))(_DAT_3ffbfdf0 + 0x24,*(undefined4 *)(iVar1 + 8),0);
  }
  FUN_40147fe4(1,8,5,0x3f436263);
  (**(code **)(_DAT_3ffc1a34 + 0xec))(_DAT_3ffbfdf0 + 0x38);
  (**(code **)(_DAT_3ffc1a34 + 0xe8))(_DAT_3ffbfdf0 + 0x38,*(undefined4 *)(iVar1 + 0xc),0);
  return;
}

