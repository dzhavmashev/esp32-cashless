// Function : FUN_4015131c
// Address  : 0x4015131c
// Size     : 72 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015131c(void)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  bVar1 = *(byte *)(_DAT_3ffbfc54 + 0x3f3);
  uVar2 = FUN_40155028();
  if ((uVar2 < bVar1) ||
     (bVar1 = *(byte *)(_DAT_3ffbfc54 + 0x3f3), uVar2 = FUN_4015505c(), bVar1 < uVar2)) {
    uVar3 = FUN_4015505c();
    FUN_40150e8c(0x1a,uVar3,DAT_3ffc8a05 == '\0');
  }
  return 0;
}

