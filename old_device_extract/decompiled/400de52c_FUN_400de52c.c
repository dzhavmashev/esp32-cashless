// Function : FUN_400de52c
// Address  : 0x400de52c
// Size     : 215 bytes


void FUN_400de52c(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  do {
    func_0x4009183c(5000);
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    FUN_400f06a4(0x3ffc5490,"ISABLED",*(undefined4 *)(param_1 + 0xcc),
                 *(undefined4 *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xd4),
                 *(undefined4 *)(param_1 + 0xd8),*(undefined4 *)(param_1 + 0xdc),
                 *(undefined4 *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0xe8));
    memw();
    memw();
    memw();
    memw();
    memw();
    FUN_400f06a4(0x3ffc5490," E=%lu\n",*(undefined4 *)(param_1 + 0xec),
                 *(undefined4 *)(param_1 + 0xf0),*(undefined4 *)(param_1 + 0xf8),
                 *(undefined4 *)(param_1 + 0xfc),*(undefined4 *)(param_1 + 0x108));
    memw();
    uVar1 = FUN_400de510(param_1,*(undefined4 *)(param_1 + 0x28));
    memw();
    uVar2 = FUN_400de510(param_1,*(undefined4 *)(param_1 + 0x4c));
    memw();
    memw();
    memw();
    FUN_400f06a4(0x3ffc5490," E=%lu\n",uVar1,uVar2,*(undefined2 *)(param_1 + 0x2c),
                 *(undefined2 *)(param_1 + 0x2e),*(undefined4 *)(param_1 + 0x114));
    memw();
    memw();
    memw();
    FUN_400f06a4(0x3ffc5490,"ed=%lu\n",*(undefined4 *)(param_1 + 0x10c),
                 *(undefined4 *)(param_1 + 0x110),*(undefined4 *)(param_1 + 0x118));
    FUN_400f06a4(0x3ffc5490,"TX=%lu\n",*(undefined2 *)(param_1 + 0x30),
                 *(undefined2 *)(param_1 + 0x52),*(undefined4 *)(param_1 + 0x34));
  } while( true );
}

