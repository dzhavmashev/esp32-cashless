// Function : FUN_40115aec
// Address  : 0x40115aec
// Size     : 51 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40115aec(void)

{
  byte bVar1;
  int *piVar2;
  
  for (piVar2 = (int *)_DAT_3ffc83fc; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    bVar1 = *(byte *)((int)piVar2 + 0xeb);
    if (((((bVar1 & 1) != 0) && ((bVar1 & 4) != 0)) && (piVar2[1] != 0)) &&
       (((bVar1 & 8) != 0 && ((char)bVar1 < '\0')))) {
      FUN_40115ac4(piVar2,piVar2 + 1);
    }
  }
  return;
}

