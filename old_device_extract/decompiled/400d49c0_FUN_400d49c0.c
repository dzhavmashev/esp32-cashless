// Function : FUN_400d49c0
// Address  : 0x400d49c0
// Size     : 127 bytes


bool FUN_400d49c0(int param_1,undefined1 *param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  byte bVar6;
  
  uVar4 = *(undefined4 *)(param_1 + 4);
  uVar5 = *(undefined4 *)(param_1 + 0xc);
  iVar2 = FUN_400d48f8(uVar4,uVar5);
  if ((iVar2 == 0) || ((*(byte *)(iVar2 + 8) & 0x7f) != 6)) {
    return (bool)*param_2;
  }
  piVar3 = (int *)FUN_400d48f8(uVar4,uVar5);
  if (piVar3 == (int *)0x0) {
    return false;
  }
  bVar6 = *(byte *)(piVar3 + 2) & 0x7f;
  if (bVar6 == 8) {
LAB_400d4a32:
    bVar1 = *piVar3 != 0 || piVar3[1] != 0;
  }
  else {
    if (bVar6 < 9) {
      if ((*(byte *)(piVar3 + 2) & 0x7f) == 0) {
        return false;
      }
      if (bVar6 == 6) {
        return (bool)(char)*piVar3;
      }
    }
    else {
      if (bVar6 == 10) goto LAB_400d4a32;
      if (bVar6 == 0xc) {
        iVar2 = (*(code *)&SUB_400636a8)(*piVar3,piVar3[1],0,0);
        return iVar2 != 0;
      }
    }
    bVar1 = true;
  }
  return bVar1;
}

