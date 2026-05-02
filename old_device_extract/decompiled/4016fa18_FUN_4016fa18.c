// Function : FUN_4016fa18
// Address  : 0x4016fa18
// Size     : 39 bytes


int FUN_4016fa18(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  while ((iVar1 = (*(code *)&SUB_40094d60)(param_1), iVar1 == 0 &&
         (pcVar2 = (code *)FUN_40170010(), pcVar2 != (code *)0x0))) {
    (*pcVar2)();
  }
  return iVar1;
}

