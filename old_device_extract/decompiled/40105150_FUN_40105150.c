// Function : FUN_40105150
// Address  : 0x40105150
// Size     : 49 bytes


int FUN_40105150(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((param_1 != 0) && (iVar1 = (*(code *)&SUB_40094d60)(param_2 + 1), iVar2 = 0, iVar1 != 0)) {
    iVar2 = (*(code *)&SUB_4008b3d0)(iVar1,param_1,param_2);
    *(undefined1 *)(iVar2 + param_2) = 0;
    memw();
  }
  memw();
  return iVar2;
}

