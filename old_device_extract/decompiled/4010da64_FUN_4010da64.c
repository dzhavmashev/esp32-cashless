// Function : FUN_4010da64
// Address  : 0x4010da64
// Size     : 139 bytes


undefined4 FUN_4010da64(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return 0xf0;
  }
  iVar3 = *(int *)(param_1 + 0xa4);
  bVar1 = *(byte *)(iVar3 + 0xd);
  *(undefined4 *)(param_1 + 0xa4) = 0;
  if (*(code **)(param_1 + 0xb0) == (code *)0x0) {
    cVar2 = FUN_4010da34(0,param_1,iVar3,0);
  }
  else {
    memw();
    cVar2 = (**(code **)(param_1 + 0xb0))(*(undefined4 *)(param_1 + 0x38),param_1,iVar3);
  }
  if (cVar2 == '\0') {
    if ((bVar1 & 0x20) == 0) {
      return 0;
    }
    if (*(short *)(param_1 + 0x54) != 0x1680) {
      *(short *)(param_1 + 0x54) = *(short *)(param_1 + 0x54) + 1;
      memw();
    }
    if (*(code **)(param_1 + 0xb0) == (code *)0x0) {
      return 0;
    }
    memw();
    cVar2 = (**(code **)(param_1 + 0xb0))(*(undefined4 *)(param_1 + 0x38),param_1,0);
    if (cVar2 != -0xd) {
      return 0;
    }
  }
  else if (cVar2 != -0xd) {
    *(int *)(param_1 + 0xa4) = iVar3;
    memw();
    return 0xfb;
  }
  return 0xf3;
}

