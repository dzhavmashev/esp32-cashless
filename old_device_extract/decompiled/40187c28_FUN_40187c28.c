// Function : FUN_40187c28
// Address  : 0x40187c28
// Size     : 95 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40187c28(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = _DAT_3ffc8804;
  if (_DAT_3ffc8804 == 0) {
    FUN_40147fe4(1,0x800,1,"","l_chm.c",0x92a);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  bVar1 = *(byte *)(_DAT_3ffbfc54 + 0x3f6);
  uVar5 = 0;
  while( true ) {
    if (bVar1 < uVar5) {
      return 0;
    }
    if ((*param_1 & 1) != 0) break;
    iVar3 = *(int *)(uVar5 * 4 + iVar2 + 0xec);
    if ((iVar3 != 0) && (iVar4 = (*(code *)&SUB_4008b33c)(param_1,iVar3 + 4,6), iVar4 == 0)) {
      return iVar3;
    }
    uVar5 = uVar5 + 1 & 0xff;
  }
  return *(int *)(iVar2 + 0xec);
}

