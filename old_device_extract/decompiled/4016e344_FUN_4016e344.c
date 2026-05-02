// Function : FUN_4016e344
// Address  : 0x4016e344
// Size     : 111 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016e344(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  char cVar6;
  byte local_30 [48];
  
  pbVar5 = local_30;
  cVar6 = '\0';
  local_30[0] = DAT_3ffc3ae0;
  local_30[1] = DAT_3ffc3ae1;
  local_30[2] = DAT_3ffc3ae2;
  local_30[3] = DAT_3ffc3ae3;
  memw();
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 1;
    uVar4 = (**(code **)(_DAT_3ffc7e64 + 0x98))(0x62,1,iVar2);
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    if (bVar1 != uVar4) {
      cVar6 = cVar6 + '\x01';
    }
    iVar2 = iVar3;
  } while (iVar3 != 4);
  if (cVar6 != '\0') {
    DAT_3ffc075f = 0x2a;
    memw();
    (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x6a,2,0,0x2a);
  }
  return;
}

