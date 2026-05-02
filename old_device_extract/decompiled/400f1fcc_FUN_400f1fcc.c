// Function : FUN_400f1fcc
// Address  : 0x400f1fcc
// Size     : 135 bytes


int FUN_400f1fcc(int *param_1,undefined1 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if ((param_3 == 0 || param_2 == (undefined1 *)0x0) || (param_1 == (int *)0x0)) {
    return 0;
  }
  if (*param_1 != 0) {
    do {
      iVar1 = func_0x40090018(*param_1,0xffffffff);
    } while (iVar1 != 1);
  }
  iVar1 = 0;
  if (*(char *)((int)param_1 + 5) != '\0') {
    *(undefined1 *)((int)param_1 + 5) = 0;
    param_3 = param_3 + -1;
    *param_2 = *(undefined1 *)((int)param_1 + 6);
    iVar1 = 1;
    if (param_3 == 0) goto LAB_400f203f;
    param_2 = param_2 + 1;
  }
  iVar2 = FUN_400f7574((char)param_1[1],param_2,param_3,(uint)(param_4 * 1000) / 1000);
  iVar1 = (uint)(-1 < iVar2) * iVar2 + iVar1;
LAB_400f203f:
  if (*param_1 != 0) {
    func_0x4008fac0(*param_1,0,0);
  }
  return iVar1;
}

