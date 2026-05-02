// Function : FUN_401258e4
// Address  : 0x401258e4
// Size     : 106 bytes


undefined4 FUN_401258e4(int *param_1,int param_2,int param_3,undefined1 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_4015a398();
  if ((param_2 != 0 && param_3 != 0) && (param_1 != (int *)0x0 && (param_2 != 0 && param_3 != 0))) {
    if (iVar1 == 0) {
      return 1;
    }
    if (*(int *)(*(int *)(iVar1 + 0x18) + 4) == 0) {
LAB_4012591a:
      FUN_401254a4(*(undefined4 *)(iVar1 + 0x18),*param_1);
      return 1;
    }
    if (*param_1 != 0) {
      FUN_401247e0();
    }
    iVar2 = FUN_40124780(*(undefined4 *)(iVar1 + 0x18),param_2);
    *param_1 = iVar2;
    if (iVar2 != 0) {
      memw();
      iVar2 = FUN_40125cf4(*(undefined4 *)(iVar1 + 0x18),iVar2,param_3,param_4);
      if (iVar2 == 0) goto LAB_4012591a;
    }
  }
  return 0;
}

