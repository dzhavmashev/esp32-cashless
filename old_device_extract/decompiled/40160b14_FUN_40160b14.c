// Function : FUN_40160b14
// Address  : 0x40160b14
// Size     : 173 bytes


void FUN_40160b14(uint param_1)

{
  int *piVar1;
  int iVar2;
  
  if (4 < (param_1 & 0xff)) {
    memw();
    FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"omplete",0x48a);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar2 = (param_1 & 0xff) * 0x24;
  piVar1 = (int *)(&DAT_3ffc7b1c + iVar2);
  if (*piVar1 == 0) {
    memw();
    FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"omplete",0x48c);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((&DAT_3ffc7b2e)[iVar2] != '\x01') {
    memw();
    FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"omplete",0x48d);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (((**(uint **)(*piVar1 + 0x2c) & 0x300) == 0) && (iVar2 = FUN_401600f4(), iVar2 != 0)) {
    FUN_4016098c(piVar1,1,0);
    return;
  }
  FUN_40160728(piVar1,1,1,0);
  return;
}

