// Function : FUN_40133bc0
// Address  : 0x40133bc0
// Size     : 215 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40133bc0(int param_1,byte *param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  byte local_54 [32];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  (*(code *)&SUB_4008b530)(local_54,0,0x30);
  iVar1 = 0;
  do {
    iVar3 = 0x10;
    do {
      iVar3 = iVar3 + -1;
      cVar2 = *(char *)(param_1 + iVar3) + '\x01';
      *(char *)(param_1 + iVar3) = cVar2;
      memw();
    } while (iVar3 != 0 && cVar2 == '\0');
    memw();
    iVar3 = FUN_4013cf6c(param_1 + 0x20,1,param_1,local_54 + iVar1);
    if (iVar3 != 0) goto LAB_40133c71;
    iVar1 = iVar1 + 0x10;
  } while (iVar1 != 0x30);
  local_54[0] = *param_2 ^ local_54[0];
  memw();
  memw();
  iVar3 = FUN_4013cea0(param_1 + 0x20,local_54,0x100);
  if (iVar3 == 0) {
    (*(code *)&SUB_4008b3d0)(param_1,auStack_34,0x10);
  }
LAB_40133c71:
  FUN_4013ae54(local_54,0x30);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar3;
}

