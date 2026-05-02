// Function : FUN_4011a828
// Address  : 0x4011a828
// Size     : 213 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011a828(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = (uint)DAT_3ffc64c8 * 0x30;
  if (((((*param_1 == *(int *)(&DAT_3ffc85f8 + iVar2)) &&
        (param_1[1] == *(int *)(&DAT_3ffc85fc + iVar2))) &&
       (param_1[2] == *(int *)(&DAT_3ffc8600 + iVar2))) &&
      ((param_1[3] == *(int *)(&DAT_3ffc8604 + iVar2) &&
       (iVar3 = (int)(short)(ushort)DAT_3ffc64c8, (char)param_1[4] == (&DAT_3ffc8608)[iVar2])))) ||
     (iVar3 = FUN_401189c4(param_1), -1 < iVar3)) {
    iVar4 = iVar3 * 0x30;
    iVar2 = (uint)DAT_3ffc64c9 * 0x2c;
    if (((*(int *)(iVar4 + 0x3ffc860c) != *(int *)(&DAT_3ffc851c + iVar2)) ||
        (*(int *)(iVar4 + 0x3ffc8610) != *(int *)(&DAT_3ffc8520 + iVar2))) ||
       ((*(int *)(iVar4 + 0x3ffc8614) != *(int *)(&DAT_3ffc8524 + iVar2) ||
        ((*(int *)(iVar4 + 0x3ffc8618) != *(int *)(&DAT_3ffc8528 + iVar2) ||
         (bVar1 = DAT_3ffc64c9, *(char *)(iVar4 + 0x3ffc861c) != (&DAT_3ffc852c)[iVar2])))))) {
      bVar1 = FUN_40118980(iVar3 * 0x30 + 0x3ffc860c);
    }
    if ((-1 < (char)bVar1) && (iVar2 = (char)bVar1 * 0x2c, 1 < (byte)(&DAT_3ffc8540)[iVar2])) {
      (&DAT_3ffc8540)[iVar2] = 2;
      memw();
      *(undefined4 *)(&DAT_3ffc8544 + iVar2) = _DAT_3ffbe0d4;
    }
  }
  memw();
  return;
}

