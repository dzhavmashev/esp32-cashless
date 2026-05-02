// Function : FUN_40123228
// Address  : 0x40123228
// Size     : 72 bytes


void FUN_40123228(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int extraout_a3;
  int iVar2;
  
  iVar2 = param_2;
  if (param_1 == (undefined4 *)0x0) {
    (*(code *)&SUB_40094c54)("ump/src/core_dump_checksum.c",0x58,"_finish","t_stack");
    iVar2 = extraout_a3;
  }
  if (param_2 == 0) {
    uVar1 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc1765,uVar1,0x3ffc179c);
  }
  else {
    uVar1 = (*(code *)&SUB_4005cfec)(*param_1,iVar2,param_3);
    *param_1 = uVar1;
    param_1[1] = param_1[1] + param_3;
  }
  memw();
  return;
}

