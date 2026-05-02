// Function : FUN_400e0528
// Address  : 0x400e0528
// Size     : 90 bytes


bool FUN_400e0528(int *param_1)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  
  if (param_1 == (int *)0x0) {
    return false;
  }
  bVar3 = *(byte *)(param_1 + 2) & 0x7f;
  if (bVar3 == 8) {
LAB_400e0572:
    bVar1 = *param_1 != 0 || param_1[1] != 0;
  }
  else {
    if (bVar3 < 9) {
      if ((*(byte *)(param_1 + 2) & 0x7f) == 0) {
        return false;
      }
      if (bVar3 == 6) {
        return (bool)(char)*param_1;
      }
    }
    else {
      if (bVar3 == 10) goto LAB_400e0572;
      if (bVar3 == 0xc) {
        iVar2 = (*(code *)&SUB_400636a8)(*param_1,param_1[1],0,0);
        return iVar2 != 0;
      }
    }
    bVar1 = true;
  }
  return bVar1;
}

