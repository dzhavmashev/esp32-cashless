// Function : FUN_40170864
// Address  : 0x40170864
// Size     : 50 bytes


int FUN_40170864(int param_1)

{
  int iVar1;
  int in_t0;
  
  iVar1 = (*(code *)&SUB_40094d60)(param_1 + 0x60);
  if ((iVar1 == 0) && (iVar1 = FUN_40170808(param_1 + 0x60), iVar1 == 0)) {
    iVar1 = in_t0;
    FUN_401701ec();
  }
  iVar1 = (*(code *)&SUB_4008b530)(iVar1,0,0x60);
  return iVar1 + 0x60;
}

