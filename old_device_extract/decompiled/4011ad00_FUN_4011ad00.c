// Function : FUN_4011ad00
// Address  : 0x4011ad00
// Size     : 40 bytes


void FUN_4011ad00(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)&SUB_4008fab8)(*param_1,0,0);
  if (iVar1 != 1) {
    (*(code *)&SUB_40094c54)("e mutex",0x62,"sem_new","_arch.c");
  }
  return;
}

