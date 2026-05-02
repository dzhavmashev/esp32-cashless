// Function : FUN_4018f628
// Address  : 0x4018f628
// Size     : 101 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018f628(void)

{
  int iVar1;
  int unaff_retaddr;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  if (unaff_retaddr == 0) {
    cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x401cf6b4();
  iVar4 = 0;
  puVar2 = (undefined4 *)&DAT_3ff4e000;
  do {
    iVar1 = _DAT_60033c00;
    memw();
    do {
      uVar3 = (*pcRam4018f62c)(puVar2);
      if ((uVar3 & 0x2000000) == 0) goto LAB_4018f673;
      memw();
    } while ((uint)(_DAT_60033c00 - iVar1) < 3);
    (*_FUN_4018f628)(0x3ffc332c,iVar4);
    memw();
    *puVar2 = 0;
    do {
      uVar3 = (*pcRam4018f62c)(puVar2);
    } while ((uVar3 & 0x2000000) != 0);
LAB_4018f673:
    iVar4 = iVar4 + 1;
    puVar2 = puVar2 + 1;
    if (iVar4 == 5) {
      return;
    }
  } while( true );
}

