// Function : FUN_400fc6c0
// Address  : 0x400fc6c0
// Size     : 6 bytes


/* WARNING: Control flow encountered bad instruction data */

int FUN_400fc6c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined1 uVar1;
  int unaff_retaddr;
  int iVar2;
  undefined4 *extraout_a3;
  undefined4 uVar3;
  
  if (unaff_retaddr == 0) {
    cust0();
    uVar1 = *(undefined1 *)(param_4 + 0x38);
    func_0x40107798(param_1,param_2,uRam400c1ecc);
    iVar2 = (*(code *)&SUB_40082da0)(extraout_a3,uVar1);
    if (iVar2 != 0x10) {
      uVar3 = *extraout_a3;
      if (extraout_a3[1] != 1) goto LAB_400fc705;
      iVar2 = (*(code *)&SUB_4008fc8c)(uVar3);
      while (iVar2 != 1) {
        uVar3 = (*(code *)&SUB_40094c54)("pthread/pthread.c",0x254,"_unlock","orted!\n");
LAB_400fc705:
        iVar2 = (*(code *)&SUB_4008fab8)(uVar3,0,0);
      }
      (*(code *)&SUB_400902d4)(*extraout_a3);
      (*(code *)&SUB_40094d80)(extraout_a3);
      iVar2 = 0;
    }
    return iVar2;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

