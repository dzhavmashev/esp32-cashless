// Function : FUN_4016fffc
// Address  : 0x4016fffc
// Size     : 15 bytes


/* WARNING: Control flow encountered bad instruction data */

void FUN_4016fffc(void)

{
  undefined4 unaff_retaddr;
  int in_a5;
  
  FUN_401701ec();
  cust0();
  *(undefined4 *)(in_a5 + 0x290) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

