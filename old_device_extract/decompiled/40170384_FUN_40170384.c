// Function : FUN_40170384
// Address  : 0x40170384
// Size     : 40 bytes


bool FUN_40170384(char *param_1,char *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  if ((param_1 != param_2) && (bVar2 = false, *param_1 != '*')) {
    iVar1 = (*(code *)&SUB_4008bdec)(param_1,param_2);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

