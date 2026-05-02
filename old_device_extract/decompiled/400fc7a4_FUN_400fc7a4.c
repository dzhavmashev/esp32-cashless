// Function : FUN_400fc7a4
// Address  : 0x400fc7a4
// Size     : 6 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x400fc83d) overlaps instruction at (ram,0x400fc83c)
    */

int FUN_400fc7a4(int param_1)

{
  int unaff_retaddr;
  undefined4 *puVar1;
  int *piVar2;
  uint in_a15;
  
  if (unaff_retaddr == 0) {
    cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cust0();
  if (0xff < in_a15) {
    param_1 = unaff_retaddr + 10;
  }
  puVar1 = (undefined4 *)(*(code *)&SUB_400916b4)(0);
  if (puVar1 != (undefined4 *)0x0) {
    for (piVar2 = (int *)*puVar1; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {
      if (param_1 == *piVar2) {
        return piVar2[1];
      }
    }
  }
  return 0;
}

