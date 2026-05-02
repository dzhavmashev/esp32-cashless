// Function : FUN_4010daf0
// Address  : 0x4010daf0
// Size     : 157 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010daf0(void)

{
  int iVar1;
  int iVar2;
  
  DAT_3ffc6334 = DAT_3ffc6334 + '\x01';
  memw();
  iVar1 = _DAT_3ffc840c;
  while( true ) {
    if (iVar1 == 0) {
      memw();
      return;
    }
    if (*(char *)(iVar1 + 0x4a) == DAT_3ffc6334) break;
    *(char *)(iVar1 + 0x4a) = DAT_3ffc6334;
    memw();
    if ((*(ushort *)(iVar1 + 0x46) & 1) != 0) {
      *(ushort *)(iVar1 + 0x46) = *(ushort *)(iVar1 + 0x46) | 2;
      memw();
      memw();
      FUN_40112a70(iVar1);
      *(ushort *)(iVar1 + 0x46) = *(ushort *)(iVar1 + 0x46) & 0xfffc;
      memw();
    }
    if ((*(ushort *)(iVar1 + 0x46) & 8) != 0) {
      *(ushort *)(iVar1 + 0x46) = *(ushort *)(iVar1 + 0x46) & 0xfff7;
      memw();
      memw();
      FUN_4010caf4(iVar1);
    }
    iVar2 = *(int *)(iVar1 + 0x34);
    if (*(int *)(iVar1 + 0xa4) == 0) goto LAB_4010db83;
    DAT_3ffc8408 = '\0';
    memw();
    memw();
    FUN_4010da64(iVar1);
    iVar1 = _DAT_3ffc840c;
    if (DAT_3ffc8408 == '\0') {
LAB_4010db83:
      iVar1 = iVar2;
    }
  }
  iVar2 = *(int *)(iVar1 + 0x34);
  goto LAB_4010db83;
}

