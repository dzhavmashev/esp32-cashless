// Function : FUN_4016d1c4
// Address  : 0x4016d1c4
// Size     : 373 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016d1c4(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  char cVar8;
  
  if ((_DAT_3ffca4c8 & 0x40000) != 0) {
    return;
  }
  FUN_4016bc68(0);
  (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x6b,2,1,3,0,0xf);
  (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x6b,2,2,3,0,7);
  (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x6b,2,2,6,4,3);
  uVar4 = 0x50;
  uVar5 = 1;
  cVar8 = '\x01';
  iVar3 = 0x3ffca508;
  do {
    FUN_4016f7a8((int)cVar8,DAT_3ffca5b9,0);
    if (uVar5 == 1) {
      cVar8 = '\x04';
      while( true ) {
        (**(code **)(_DAT_3ffc7e64 + 0x44))(1,0x80,uVar4,0,0);
        (*(code *)&SUB_40008534)(2);
        uVar2 = (**(code **)(_DAT_3ffc7e64 + 0x178))(_DAT_3ffca42c);
        uVar2 = uVar2 >> 2 & 0xffff;
        iVar7 = uVar2 - 0x28;
        cVar1 = (char)iVar7;
        iVar7 = (int)(short)iVar7;
        if ((uVar2 - 0x25 & 0xffff) < 7) break;
        if (iVar7 < 1) {
          iVar7 = iVar7 * 3;
          if (iVar7 < 0) {
            iVar7 = iVar7 + 3;
          }
          cVar1 = (char)(iVar7 >> 2);
        }
        iVar7 = (int)(char)((char)uVar4 + cVar1);
        iVar7 = (uint)(iVar7 < 0x78) * iVar7 + (uint)(iVar7 >= 0x78) * 0x78;
        cVar8 = cVar8 + -1;
        uVar4 = (uint)(-1 < iVar7) * iVar7;
        if (cVar8 == '\0') {
          uVar4 = uVar4 & 0xff;
          break;
        }
        uVar4 = uVar4 & 0xff;
      }
      DAT_3ffc075e = (char)uVar4 + -8;
      memw();
      (**(code **)(_DAT_3ffc7e64 + 0x170))(0x80,uVar4,0,iVar3);
    }
    else {
      (**(code **)(_DAT_3ffc7e64 + 0x170))(0x80,uVar4,0,iVar3);
      if (uVar5 == 3) {
        DAT_3ffca513 = DAT_3ffca510;
        DAT_3ffca511 = DAT_3ffca50e;
        DAT_3ffca512 = DAT_3ffca50f;
        memw();
        (**(code **)(_DAT_3ffc7e64 + 0x124))();
        _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x40000;
        return;
      }
    }
    pcVar6 = (char *)(uVar5 + 0x3ffc3a64);
    iVar3 = iVar3 + 3;
    uVar5 = uVar5 + 1 & 0xff;
    cVar8 = *pcVar6;
  } while( true );
}

