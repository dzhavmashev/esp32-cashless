// Function : FUN_401212c4
// Address  : 0x401212c4
// Size     : 80 bytes


int FUN_401212c4(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 == 0 || param_3 == 0) || (param_1 == 0)) {
    iVar2 = 0x102;
  }
  else {
    while( true ) {
      uVar1 = FUN_40185664(param_3,8);
      (*(code *)&SUB_4008b530)(param_2,0,uVar1);
      iVar2 = FUN_40121320(param_1,param_2,param_3,0x401214f4);
      if (iVar2 != 0x1606) break;
      (*(code *)&SUB_40091834)(1);
    }
  }
  return iVar2;
}

