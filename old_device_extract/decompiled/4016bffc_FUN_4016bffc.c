// Function : FUN_4016bffc
// Address  : 0x4016bffc
// Size     : 467 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016bffc(undefined2 param_1,undefined4 param_2,ushort *param_3,undefined1 param_4,
                 char param_5,char param_6)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  ushort uVar5;
  code *pcVar6;
  char cVar7;
  short sVar8;
  byte local_40;
  byte bStack_3f;
  undefined4 uStack_30;
  ushort *puStack_2c;
  
  puStack_2c = param_3;
  _DAT_3ff450dc = (*(code *)&SUB_40084594)(&DAT_3ff450dc);
  _DAT_3ff450dc = _DAT_3ff450dc | 0x800;
  memw();
  _DAT_3ff450dc = (*(code *)&SUB_40084594)();
  _DAT_3ff450dc = _DAT_3ff450dc & 0xffffefff;
  memw();
  FUN_4016bc68(param_6 == '\x01');
  (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,2,param_1);
  if (param_6 == '\x01') {
    pcVar6 = *(code **)(_DAT_3ffc7e64 + 0xb8);
    uVar1 = (**(code **)(_DAT_3ffc7e64 + 0xbc))(1,1);
    (*pcVar6)(1,1,uVar1 | 2);
  }
  else if (param_6 == '\x02') {
    (**(code **)(_DAT_3ffc7e64 + 0x28))(1);
    (**(code **)(_DAT_3ffc7e64 + 0x118))(param_2);
    goto LAB_4016c0a5;
  }
  (**(code **)(_DAT_3ffc7e64 + 0xdc))(param_2);
LAB_4016c0a5:
  uStack_30 = (*(code *)&SUB_40084594)(&DAT_3ff460b8);
  cVar4 = '\x04';
  do {
    (**(code **)(_DAT_3ffc7e64 + 0x44))(1,param_4,param_5,0,0);
    (*(code *)&SUB_40008534)(2);
    iVar2 = (**(code **)(_DAT_3ffc7e64 + 0x134))(0);
    sVar8 = (short)(iVar2 >> 2);
    cVar7 = param_5 + '\x04';
    if ((sVar8 < 0x3e9) && (cVar7 = param_5 + -4, 599 < sVar8)) break;
    cVar4 = cVar4 + -1;
    param_5 = cVar7;
  } while (cVar4 != '\0');
  iVar2 = (int)param_5;
  iVar2 = (uint)(iVar2 < 0x78) * iVar2 + (uint)(iVar2 >= 0x78) * 0x78;
  FUN_4016be74((uint)(-1 < iVar2) * iVar2,param_4,&local_40,0);
  (**(code **)(_DAT_3ffc7e64 + 0x124))();
  if ((char)local_40 < '\x10') {
    if ((char)local_40 < -0xf) {
      local_40 = 0xf1;
      memw();
      uVar1 = 0x440;
    }
    else {
      uVar1 = (local_40 & 0x1f) << 6;
    }
  }
  else {
    uVar1 = 0x3c0;
    local_40 = 0xf;
    memw();
  }
  if ((char)bStack_3f < ' ') {
    if ((char)bStack_3f < -0x1f) {
      bStack_3f = 0xe1;
      memw();
      uVar5 = 0x21;
    }
    else {
      uVar5 = bStack_3f & 0x3f;
    }
  }
  else {
    uVar5 = 0x1f;
    bStack_3f = 0x1f;
    memw();
  }
  *puStack_2c = uVar1 | uVar5;
  memw();
  memw();
  _DAT_3ff460b8 = uStack_30;
  if (param_6 == '\x02') {
    (**(code **)(_DAT_3ffc7e64 + 0x28))(0);
  }
  uVar3 = (*(code *)&SUB_40084594)(&DAT_3ff450dc);
  memw();
  _DAT_3ff450dc = uVar3 | 0x1000;
  return;
}

