// Function : FUN_400fce14
// Address  : 0x400fce14
// Size     : 80 bytes


void FUN_400fce14(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar2 = param_1;
  do {
    if (iVar2 == 1) {
      while( true ) {
        if (param_1 == 1) {
          (*(code *)&SUB_4008d7c8)(1);
        }
        iVar1 = (*(code *)&SUB_4008e00c)(2,0x400);
        if (iVar1 != 0) goto LAB_400fce41;
        if (iVar3 != 1) break;
        iVar3 = 0;
      }
      iVar3 = iVar3 + -1;
      iVar2 = 0;
    }
LAB_400fce41:
    (*(code *)&SUB_4008d8c0)(iVar2);
    iVar1 = (*(code *)&SUB_4008e00c)(0,0x400);
    if (iVar1 != 0) {
      FUN_4011e558();
      return;
    }
  } while( true );
}

