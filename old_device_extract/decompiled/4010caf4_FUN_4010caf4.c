// Function : FUN_4010caf4
// Address  : 0x4010caf4
// Size     : 125 bytes


char FUN_4010caf4(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)(" LISTEN",0x19c,"abandon","e/tcp.c");
  }
  iVar2 = *(int *)(param_1 + 0x3c);
  if (iVar2 == 4) {
    cVar1 = FUN_40110988(param_1);
    if (cVar1 != '\0') goto LAB_4010cb47;
  }
  else {
    if (iVar2 == 7) {
      cVar1 = FUN_40110988(param_1);
      if (cVar1 != '\0') goto LAB_4010cb47;
      uVar3 = 9;
      goto LAB_4010cb2c;
    }
    if (iVar2 != 3) {
      return '\0';
    }
    cVar1 = FUN_40110988(param_1);
    if (cVar1 != '\0') {
LAB_4010cb47:
      if (cVar1 == -1) {
        *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) | 8;
        memw();
        memw();
        return '\0';
      }
      return cVar1;
    }
    FUN_4010caa8(param_1);
  }
  uVar3 = 5;
LAB_4010cb2c:
  *(undefined4 *)(param_1 + 0x3c) = uVar3;
  memw();
  FUN_40112a70(param_1);
  return '\0';
}

