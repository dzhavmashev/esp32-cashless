// Function : FUN_4015b5d8
// Address  : 0x4015b5d8
// Size     : 88 bytes


uint FUN_4015b5d8(int param_1)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = DAT_3ffca0b5 & 1;
  if ((DAT_3ffca0b5 & 1) == 0) {
    if ((DAT_3ffca0b5 & 2) == 0) goto LAB_4015b615;
    cVar1 = *(char *)(param_1 + 0xa4);
  }
  else {
    if ((DAT_3ffca0b5 & 2) != 0) {
      uVar2 = (int)(short)*(char *)(param_1 + 0xa7) * (int)(short)*(char *)(param_1 + 0xa4);
      goto LAB_4015b615;
    }
    cVar1 = *(char *)(param_1 + 0xa7);
  }
  uVar2 = (uint)cVar1;
LAB_4015b615:
  if ((((DAT_3ffca0b5 & 4) != 0) && (uVar2 != 0)) && (*(char *)(param_1 + 0xa5) != '\0')) {
    uVar2 = uVar2 + 2;
  }
  if (((DAT_3ffca0b5 & 8) != 0) && (*(char *)(param_1 + 0xaa) != '\0')) {
    uVar2 = uVar2 << 1;
  }
  return uVar2;
}

