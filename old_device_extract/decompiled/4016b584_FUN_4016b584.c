// Function : FUN_4016b584
// Address  : 0x4016b584
// Size     : 227 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016b584(char param_1)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  
  if (param_1 != '\x01') {
    _DAT_3ff5c400 = (*(code *)&SUB_40084594)(&DAT_3ff5c400);
    cVar3 = '\x02';
    iVar2 = 2;
    if (DAT_3ffca51a == '\0') {
      iVar2 = 0;
    }
    else {
      cVar3 = '\x01';
    }
    _DAT_3ff5c400 = _DAT_3ff5c400 | 0x6000;
    memw();
    (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x67,1,3,6,0,(&DAT_3ffca51c)[iVar2] - cVar3);
    (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x67,1,4,6,0,(&DAT_3ffca51c)[iVar2]);
    FUN_4016b534((int)DAT_3ffc0737);
    return;
  }
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c400);
  _DAT_3ff5c400 = uVar1 & 0xffff9fff | 0x2000;
  memw();
  (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x67,1,3,6,0,0x4c);
  (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x67,1,4,6,0,0x4e);
  FUN_4016b534((int)DAT_3ffc0736);
  return;
}

