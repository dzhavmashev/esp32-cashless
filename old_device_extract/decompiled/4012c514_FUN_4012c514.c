// Function : FUN_4012c514
// Address  : 0x4012c514
// Size     : 281 bytes


int FUN_4012c514(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  FUN_40185840(param_1,param_1[0x15]);
  (**(code **)(param_1[0x11] + 0x20))(param_1,param_1[0x33] + 4,*(undefined1 *)(*param_1 + 4));
  iVar2 = 0xc;
  if (param_1[5] == 0) {
    iVar2 = 0x24;
  }
  param_1[0x81] = iVar2;
  puVar3 = (undefined1 *)param_1[0x33];
  memw();
  (*(code *)&SUB_4008b3d0)(param_1 + 0x82,puVar3 + 4,iVar2);
  param_1[0x35] = iVar2 + 4;
  param_1[0x34] = 0x16;
  *puVar3 = 0x14;
  memw();
  iVar2 = param_1[0x11];
  if (*(char *)(iVar2 + 2) == '\0') {
    param_1[1] = param_1[1] + 1;
    memw();
  }
  else {
    iVar4 = 0xf;
    cVar1 = *(char *)(*param_1 + 4);
    if (cVar1 != '\0') {
      if (cVar1 != '\x01') goto LAB_4012c584;
      iVar4 = 10;
    }
    param_1[1] = iVar4;
  }
LAB_4012c584:
  if (*(char *)(*param_1 + 5) == '\x01') {
    *(int *)(iVar2 + 0x25c) = param_1[0x13];
    memw();
    (*(code *)&SUB_4008b3d0)(iVar2 + 0x260,param_1 + 0x37,8);
    (*(code *)&SUB_4008b530)((int)param_1 + 0xde,0,6);
    cVar1 = *(char *)((int)param_1 + 0xdd) + '\x01';
    *(char *)((int)param_1 + 0xdd) = cVar1;
    memw();
    if (cVar1 == '\0') {
      cVar1 = (char)param_1[0x37] + '\x01';
      *(char *)(param_1 + 0x37) = cVar1;
      memw();
      if (cVar1 == '\0') {
        return -0x6b80;
      }
    }
  }
  else {
    (*(code *)&SUB_4008b530)(param_1 + 0x37,0,8);
  }
  param_1[0x13] = param_1[0x15];
  param_1[0xe] = param_1[0x10];
  if (*(char *)(*param_1 + 5) == '\x01') {
    memw();
    FUN_401299a8(param_1);
  }
  iVar2 = FUN_4012a534(param_1);
  if ((iVar2 == 0) && (*(char *)(*param_1 + 5) == '\x01')) {
    iVar2 = FUN_40129fc8(param_1);
  }
  return iVar2;
}

