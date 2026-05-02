// Function : FUN_4011af6c
// Address  : 0x4011af6c
// Size     : 65 bytes


void FUN_4011af6c(int *param_1)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && ((undefined4 *)*param_1 != (undefined4 *)0x0)) {
    iVar1 = (*(code *)&SUB_400902a8)(*(undefined4 *)*param_1);
    if (iVar1 != 0) {
      (*(code *)&SUB_40094c54)("e mutex",0x185,"d_tcpip"," failed");
    }
    (*(code *)&SUB_400902d4)(*(undefined4 *)*param_1);
    (*(code *)&SUB_40094d80)(*param_1);
    *param_1 = iVar1;
  }
  memw();
  return;
}

