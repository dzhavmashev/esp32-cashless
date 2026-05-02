// Function : FUN_4015492c
// Address  : 0x4015492c
// Size     : 50 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015492c(void)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(_DAT_3ffc8804 + 0x134) <= *(int *)(_DAT_3ffc8804 + 0x138)) {
    iVar1 = *(int *)(_DAT_3ffc8804 + 0xec);
    iVar2 = FUN_40154788();
    if ((iVar2 == 0) || (*(int *)(iVar2 + 0x108) <= *(int *)(iVar1 + 0x108))) {
      FUN_401548d0(iVar1);
    }
    else {
      FUN_40154880();
    }
  }
  return 1;
}

