// Function : FUN_401645e4
// Address  : 0x401645e4
// Size     : 114 bytes


void FUN_401645e4(int param_1,byte param_2)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  
  bVar1 = *(byte *)(*(int *)(param_1 + 0x60) + 1);
  bVar3 = bVar1 + 2;
  if (param_2 <= bVar1) {
    bVar3 = param_2 + 1;
  }
  if (0x1ffffff < *(uint *)(param_1 + 0x2c) + 1) {
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) >> 1;
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) >> 1;
  }
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  *(uint *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (uint)bVar3;
  if (param_2 < 8) {
    if (param_2 < 5) {
      if (2 < param_2) goto LAB_40164648;
      cVar2 = '\0';
    }
    else {
      cVar2 = *(char *)(param_1 + 7) + '\x01';
    }
  }
  else {
    cVar2 = *(char *)(param_1 + 7) + '\x02';
    memw();
  }
  *(char *)(param_1 + 7) = cVar2;
  memw();
LAB_40164648:
  if (6 < *(byte *)(param_1 + 7)) {
    memw();
    FUN_401644f4(param_1,1);
  }
  return;
}

