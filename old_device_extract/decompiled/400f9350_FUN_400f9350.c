// Function : FUN_400f9350
// Address  : 0x400f9350
// Size     : 37 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f9350(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = _DAT_3ffc56cc;
  do {
    if (iVar2 == 0) {
      uVar1 = 0x1107;
LAB_400f936a:
      memw();
      return uVar1;
    }
    if (param_1 == *(int *)(iVar2 + 0xc)) {
      *param_2 = *(undefined4 *)(iVar2 + 8);
      uVar1 = 0;
      goto LAB_400f936a;
    }
    iVar2 = *(int *)(iVar2 + 4);
  } while( true );
}

