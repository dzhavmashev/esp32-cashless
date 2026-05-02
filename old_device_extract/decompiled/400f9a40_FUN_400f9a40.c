// Function : FUN_400f9a40
// Address  : 0x400f9a40
// Size     : 61 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f9a40(int param_1)

{
  int iVar1;
  
  FUN_400f9390();
  iVar1 = _DAT_3ffc56cc;
  do {
    if (iVar1 == 0) {
LAB_400f9a78:
      FUN_400f9378();
      return;
    }
    if (param_1 == *(int *)(iVar1 + 0xc)) {
      (*(code *)&LAB_401848e3_1)(&DAT_3ffc56cc,iVar1);
      if (*(int **)(iVar1 + 8) != (int *)0x0) {
        (**(code **)(**(int **)(iVar1 + 8) + 4))();
      }
      (*(code *)&SUB_40094d80)(iVar1);
      goto LAB_400f9a78;
    }
    iVar1 = *(int *)(iVar1 + 4);
  } while( true );
}

