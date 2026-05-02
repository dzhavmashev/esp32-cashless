// Function : FUN_400dfe3c
// Address  : 0x400dfe3c
// Size     : 39 bytes


void FUN_400dfe3c(int param_1,char param_2)

{
  char *pcVar1;
  
  FUN_400f1a40(*(undefined1 *)(param_1 + 0x25),param_2);
  pcVar1 = "ID_VERSION";
  if (param_2 == '\0') {
    pcVar1 = "_ACTIVE";
  }
  FUN_400f06a4(0x3ffc5490,&PTR_FUN_3f406884,pcVar1,*(undefined1 *)(param_1 + 0x25));
  return;
}

