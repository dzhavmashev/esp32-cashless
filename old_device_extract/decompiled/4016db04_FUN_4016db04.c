// Function : FUN_4016db04
// Address  : 0x4016db04
// Size     : 446 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016db04(void)

{
  bool bVar1;
  int iVar2;
  ushort uVar3;
  undefined1 *puVar4;
  char *pcVar5;
  code *pcVar6;
  char cVar7;
  short sStack_30;
  undefined2 uStack_2e;
  undefined1 uStack_2c;
  char acStack_2b [43];
  
  puVar4 = &DAT_3ffca4c8;
  cVar7 = '\a';
  pcVar5 = (char *)0x3ffc3a54;
  while( true ) {
    uStack_2c = 0x2e;
    memw();
    FUN_4016f7a8((int)cVar7,DAT_3ffca5b9,0);
    (**(code **)(_DAT_3ffc7e64 + 0x16c))(0x3ffca508,cVar7);
    if (cVar7 == '\a') {
      bVar1 = false;
      while( true ) {
        uStack_2e = FUN_40169e80(1);
        memw();
        FUN_4016bc68(1);
        (**(code **)(_DAT_3ffc7e64 + 0xb8))(5,1,_DAT_3ffc073a);
        (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,2,uStack_2e);
        pcVar6 = *(code **)(_DAT_3ffc7e64 + 0xb8);
        uVar3 = (**(code **)(_DAT_3ffc7e64 + 0xbc))(1);
        (*pcVar6)(1,1,uVar3 | 2);
        (**(code **)(_DAT_3ffc7e64 + 0xdc))(0x3ffca568);
        FUN_4016d398(0x20,&uStack_2c,1,0xb,acStack_2b,_DAT_3ffca42c,0x23,0);
        if ((bVar1) || ((byte)(acStack_2b[0] - 0x10U) < 9)) break;
        memw();
        sStack_30 = 0x14 - acStack_2b[0];
        (*(code *)&SUB_40088f98)(&sStack_30,&DAT_3ffc073a,&uStack_2e,1);
        bVar1 = true;
      }
      _DAT_3ffca558 = uStack_2e;
      DAT_3ffca552 = acStack_2b[0];
      memw();
      (**(code **)(_DAT_3ffc7e64 + 0x124))();
    }
    else {
      uStack_2e = FUN_40169e80(1);
      memw();
      FUN_4016bc68(1);
      (**(code **)(_DAT_3ffc7e64 + 0xb8))(5,1,_DAT_3ffc073a);
      (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,2,uStack_2e);
      pcVar6 = *(code **)(_DAT_3ffc7e64 + 0xb8);
      uVar3 = (**(code **)(_DAT_3ffc7e64 + 0xbc))(1);
      (*pcVar6)(1,1,uVar3 | 2);
      (**(code **)(_DAT_3ffc7e64 + 0xdc))(0x3ffca568);
      FUN_4016d398(0x20,&uStack_2c,1,0xb,acStack_2b,_DAT_3ffca42c,0x19,0);
      iVar2 = _DAT_3ffc7e64;
      puVar4[0x8b] = acStack_2b[0] - DAT_3ffca552;
      memw();
      (**(code **)(iVar2 + 0x124))();
    }
    puVar4 = puVar4 + 1;
    pcVar5 = pcVar5 + 1;
    if (puVar4 == &DAT_3ffca4cc) break;
    cVar7 = *pcVar5;
  }
  DAT_3ffca557 = DAT_3ffca556;
  memw();
  return;
}

